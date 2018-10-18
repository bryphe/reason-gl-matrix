// Provides: caml_mat4_create
function caml_mat4_create() {
    return joo_global_object.mat4.create();
}

// Provides: caml_mat4_get
function caml_mat4_get(matrix, index) {
    return matrix[index];
}

// Provides: caml_mat4_multiply
function caml_mat4_multiply(mOut, m1, m2) {
    return joo_global_object.mat4.multiply(mOut, m1, m2);
}

// Provides: caml_mat4_fromTranslation
function caml_mat4_fromTranslation(matrix, v) {
    return joo_global_object.mat4.fromTranslation(matrix, v);
}

// Provides: caml_mat4_fromScaling
function caml_mat4_fromScaling(matrix, v) {
    return joo_global_object.mat4.fromScaling(matrix, v);
}

// Provides: caml_mat4_lookat
function caml_mat4_lookat(matrix, eye, center, up) {
    return joo_global_object.mat4.lookAt(matrix, eye, center, up);
}

// Provides: caml_mat4_rotate
function caml_mat4_rotate(matrix, angle, vector) {
    return joo_global_object.mat4.rotate(matrix, matrix, angle, vector);
}

// Provides: caml_mat4_perspective
function caml_mat4_perspective(matrix, fov, aspectRatio, near, far) {
    return joo_global_object.mat4.perspective(matrix, fov, aspectRatio, near, far);
}

// Provides: caml_mat4_ortho_bytecode
function caml_mat4_ortho_bytecode(matrix, left, right, bottom, top, near, far) {
    return joo_global_object.mat4.ortho(matrix, left, right, bottom, top, near, far);
}

// Provides: caml_vec2_create
function caml_vec2_create() {
    return joo_global_object.vec2.create();
}

// Provides: caml_vec3_create
function caml_vec3_create() {
    return joo_global_object.vec3.create();
}

// Provides: caml_vec4_create
function caml_vec4_create() {
    return joo_global_object.vec4.create();
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

// Provides: caml_vec4_get_w
function caml_vec4_get_w(v) {
    return v[3];
}

// Provides: caml_vec2_set
function caml_vec2_set(v, x, y) {
    v[0] = x;
    v[1] = y;
}

// Provides: caml_vec3_set
function caml_vec3_set(v, x, y, z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

// Provides: caml_vec4_set
function caml_vec4_set(v, x, y, z, w) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}
