open Reglm;
open BenchFramework;

let m1 = Mat4.create();
let m2 = Mat4.create();

let mat4Create = () => {
    let _ = Mat4.create();
};

let mat4Multiply = () => {
  Mat4.multiply(m1, m2, m2);
};

let quatCreate = () => {
    let _ = Quat.create(1., 2., 3., 4.);
};

let vec4Create = () => {
    let _ = Vec4.create(1., 2., 3., 4.);
};

let vec3Create = () => {
    let _ = Vec3.create(1., 2., 3.);
};

let vec2Create = () => {
    let _ = Vec2.create(1., 2.);
};

bench(~name="Mat4: Create", ~f=mat4Create, ());
bench(~name="Mat4: Multiply", ~f=mat4Multiply, ());
bench(~name="Vec4: create", ~f=vec4Create, ());
bench(~name="Vec3: create", ~f=vec3Create, ());
bench(~name="Vec2: create", ~f=vec2Create, ());
bench(~name="Quat: create", ~f=quatCreate, ());
