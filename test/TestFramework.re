module MockSnapshotIO = {
  let readSnapshotNames = _ => [];
  let readFile: string => string = s => s;
  let removeFile: string => unit = _ => ();
  let writeFile: (string, string) => unit = (_, _) => ();
  let existsFile: string => bool = _ => false;
  let mkdirp = _ => ();
};
/* Snapshots will be virtual-modulified at some point, until then we need to inject
 * something custom with RelyInternal to make JSOO happy because the default snapshot
 * implementation uses the Unix module  */
include RelyInternal.TestFramework.MakeInternal(
          MockSnapshotIO,
          {
            let config =
              RelyInternal.TestFrameworkConfig.TestFrameworkConfig.initialize({
                snapshotDir: "test/__snapshots__",
                projectDir: "",
              });
          },
        );

// When https://github.com/facebookexperimental/reason-native/issues/207 is closed we can use the code below
/*
 include Rely.Make({
   let config =
     Rely.TestFrameworkConfig.initialize({
       snapshotDir: "test/__snapshots__",
       projectDir: "",
     });
 });
 */
