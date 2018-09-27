
#include <stdio.h>

#include <caml/mlvalues.h>
#include <caml/custom.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

extern "C" {
    CAMLprim value
    caml_print_hello(value unit)
    {
        glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
        printf("Vector: %f %f %f\n", vec.x, vec.y, vec.z);
        printf("Hello \n");
        return Val_unit;
    }

    static struct custom_operations objst_custom_ops = {
            identifier: (char*)"obj_st handling",
            finalize:    custom_finalize_default,
            compare:     custom_compare_default,
            hash:        custom_hash_default,
            serialize:   custom_serialize_default,
            deserialize: custom_deserialize_default
    };

    CAMLprim value
    caml_vec3_create(value unit) {
        CAMLparam0 ();
        glm::vec3 vec = glm::vec3();
        float* vptr = (glm::value_ptr(vec));
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 3, 0, 1);
        memcpy((void *)Data_custom_val(v), (void *)vptr, sizeof(float) * 3);
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec3_set(value vVec, value vX, value vY, value vZ) {
        float *vptr = (float *)Data_custom_val(vVec);
        float x = Double_val(vX);
        float y = Double_val(vY);
        float z = Double_val(vZ);
        vptr[0] = x;
        vptr[1] = y;
        vptr[2] = z;
        return Val_unit;
    }

    double getByIndex(value vDat, int index) {
        float *vf = (float *)Data_custom_val(vDat);
        double d = vf[index];
        return d;
    }

    CAMLprim value
    caml_vec3_get_x(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 0));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_get_y(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 1));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_get_z(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 2));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_debug_print(value vVec) {
        return Val_unit;
    }

    CAMLprim value
    caml_mat4_create(value unit) {
        CAMLparam0 ();
        glm::mat4 mat = glm::mat4(1.0f);
        float* ptr = (glm::value_ptr(mat));
        /* for(int i = 0; i < 16; i++) { */
        /*     printf("index: %d val: %f address: %d\n", i, ((float *)ptr)[i], (ptr + i)); */
        /* } */
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 16, 0, 1);
        /* printf("data custom val pointer: %d\n", (void *)Data_custom_val(v)); */
        /* printf("data custom val pointer2: %d\n", (void *)Data_custom_val(v)); */

        memcpy((void *)Data_custom_val(v), (void *)ptr, sizeof(float) * 16);
        float *vf = (float *)Data_custom_val(v);
        /* printf("pointer: %d\n", vf); */
        /* for(int i = 0; i < 16; i++) { */
        /*     printf("index: %d val: %f address: %d\n", i, ((float *)vf)[i], (vf + i)); */
        /* } */
        CAMLreturn(v);
    }

    CAMLprim value
    caml_mat4_fromScaling(value vMat, value vVec) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vec = (float*)(Data_custom_val(vVec));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vec = glm::make_vec3(vec);

        glm::mat4 result = glm::scale(glm_matrix, glm_vec);

        const float *outMatrix = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_fromTranslation(value vMat, value vVec) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vec = (float*)(Data_custom_val(vVec));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vec = glm::make_vec3(vec);

        glm::mat4 result = glm::translate(glm_matrix, glm_vec);

        const float *outMatrix = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_lookat(value vMat, value vEye, value vCenter, value vUp) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vecEye = (float*)(Data_custom_val(vEye));
        float* vecCenter = (float*)(Data_custom_val(vCenter));
        float* vecUp = (float*)(Data_custom_val(vUp));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vEye = glm::make_vec3(vecEye);
        glm::vec3 glm_vCenter = glm::make_vec3(vecCenter);
        glm::vec3 glm_vUp = glm::make_vec3(vecUp);

        glm::mat4 result = glm::lookAt(glm_vEye, glm_vCenter, glm_vUp);

        const float *outMatrix = (const float*)(glm::value_ptr(result));
        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_multiply(value vOut, value vM1, value vM2) {
        float* pOutMatrix = (float*)(Data_custom_val(vOut));
        const float* pM1 = (const float*)(Data_custom_val(vM1));
        const float* pM2 = (const float*)(Data_custom_val(vM2));

        glm::mat4 m1 = glm::make_mat4(pM1);
        glm::mat4 m2 = glm::make_mat4(pM2);
        glm::mat4 result = m1 * m2;

        const float* pResult = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            pOutMatrix[i] = pResult[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_get(value vMat, value vIndex) {
        CAMLparam2(vMat, vIndex);
        float v = getByIndex(vMat, Int_val(vIndex));
        CAMLlocal1(ret);
        ret = caml_copy_double(v);
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_mat4_debug_print(value vMat) {
        const float* matrix = (const float*)(Data_custom_val(vMat));

        for(int i = 0; i < 16; i++) {
            printf("index: %d val: %f\n", i, matrix[i]);
        }
        return Val_unit;
    }
}
