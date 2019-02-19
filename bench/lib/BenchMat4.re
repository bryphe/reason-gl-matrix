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

bench(~name="Mat4: Create", ~f=mat4Create, ());
bench(~name="Mat4: Multiply", ~f=mat4Multiply, ());
