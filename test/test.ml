open Reglm

(*MAT4*)

(* simple test for identity matrix *)
let () =
    let m = Mat4.create () in
    let m00 = (Mat4.get m 0) in
    let m11 = (Mat4.get m 5) in
    let m22 = (Mat4.get m 10) in
    let m33 = (Mat4.get m 15) in
    assert (m00 = 1.);
    assert (m11 = 1.);
    assert (m22 = 1.);
    assert (m33 = 1.);
;;

(*VEC3*)
let () =
    let v = Vec3.create () in
    let x = Vec3.get_x v in
    let y = Vec3.get_y v in
    let z = Vec3.get_z v in
    assert (x = 0.0);
    assert (y = 0.0);
    assert (z = 0.0);
;;

(*set / get test*)
let () =
    let v = Vec3.create() in
    let _ = Vec3.set v 10. 10. 10. in
    let x = Vec3.get_x v in
    let y = Vec3.get_y v in
    let z = Vec3.get_z v in
    assert (x = 10.0);
    assert (y = 10.0);
    assert (z = 10.0);

