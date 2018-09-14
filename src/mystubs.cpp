
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
            identifier: "obj_st handling",
            finalize:    custom_finalize_default,
            compare:     custom_compare_default,
            hash:        custom_hash_default,
            serialize:   custom_serialize_default,
            deserialize: custom_deserialize_default
    };

    CAMLprim value
    caml_mat4_create(value unit) {
        CAMLparam0 ();
        glm::mat4 mat = glm::mat4(1.0f);
        printf("creating");
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
    caml_mat4_get(value vMat, value vIndex) {
        CAMLparam2(vMat, vIndex);
        CAMLlocal1(ret);
        const float* matrix = (const float*)(Data_custom_val(vMat));
        double d = matrix[Int_val(vIndex)];
        ret = caml_copy_double(d);
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
