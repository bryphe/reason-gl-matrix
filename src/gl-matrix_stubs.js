// Provides: caml_mat4_create
function caml_mat4_create() {
    return mat4.create();
}

// Provides: caml_mat4_get
function caml_mat4_get(matrix, index) {
    return matrix[index];
}

// Provides: caml_vec3_create
function caml_vec3_create() {
    return vec3.create();
}

// Provides: caml_vec3_get_x
function caml_vec3_get_x(v) {
    return v[0];
}

// Provides: caml_vec3_get_y
function caml_vec3_get_y(v) {
    return v[1];
}

// Provides: caml_vec3_get_z
function caml_vec3_get_z(v) {
    return v[2];
}

// Provides: caml_vec3_set
function caml_vec3_set(v, x, y, z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}
