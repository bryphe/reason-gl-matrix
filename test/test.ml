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

(* fromTranslation *)
let () =
    let m = Mat4.create () in
    let v = Vec3.create () in
    let _ = Vec3.set v 11. 12. 13. in
    let _ = Mat4.fromTranslation m v in
    let m03 = Mat4.get m 12 in
    let m13 = Mat4.get m 13 in
    let m23 = Mat4.get m 14 in
    assert (m03 = 11.);
    assert (m13 = 12.);
    assert (m23 = 13.);
;;

(* fromScale *)
let () =
    let m = Mat4.create () in
    let v = Vec3.create () in
    let _ = Vec3.set v 2. 3. 4. in
    let _ = Mat4.fromScaling m v in
    let m00 = Mat4.get m 0 in
    let m11 = Mat4.get m 5 in
    let m22 = Mat4.get m 10 in
    assert (m00 = 2.);
    assert (m11 = 3.);
    assert (m22 = 4.);
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
    let _ = Vec3.set v 10. 11. 12. in
    let x = Vec3.get_x v in
    let y = Vec3.get_y v in
    let z = Vec3.get_z v in
    assert (x = 10.0);
    assert (y = 11.0);
    assert (z = 12.0);

