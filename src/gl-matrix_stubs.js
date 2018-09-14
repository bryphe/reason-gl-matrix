// Provides: caml_mat4_create
function caml_mat4_create() {
    return mat4.create();
}

// Provides: caml_mat4_get
function caml_mat4_get(matrix, index) {
    return matrix[index];
}
