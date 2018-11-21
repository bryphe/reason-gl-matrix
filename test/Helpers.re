let assertFloatsEqual = (expected, actual) => {
  let equal = abs_float(expected -. actual) < 0.00001;

  print_endline(
    "[assertFloatsEqual] Expected: "
    ++ string_of_float(expected)
    ++ " Actual: "
    ++ string_of_float(actual),
  );
  assert(equal);
};
