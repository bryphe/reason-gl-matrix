open Reglm;
open BenchFramework;

let mat4Multiply = () => {
  let m1 = Mat4.create();
  let m2 = Mat4.create();
  Mat4.multiply(m1, m2, m2);
};

bench(~name="Mat4: Multiply", ~f=mat4Multiply, ());
