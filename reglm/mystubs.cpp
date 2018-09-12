
#include <stdio.h>

#include <caml/mlvalues.h>

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
}
