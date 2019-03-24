// Provides: caml_quat_create_byte
function caml_quat_create_byte(x, y, z, w) {
    return joo_global_object.quat.fromValues(x, y, z, w);
}

// Provides: caml_quat_get_x
function caml_quat_get_x(q) {
    return q[0];
}
// Provides: caml_quat_get_y
function caml_quat_get_y(q) {
    return q[1];
}
// Provides: caml_quat_get_z
function caml_quat_get_z(q) {
    return q[2];
}
// Provides: caml_quat_get_w
function caml_quat_get_w(q) {
    return q[3];
}
