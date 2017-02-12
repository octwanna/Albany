##*****************************************************************//
##    Albany 3.0:  Copyright 2016 Sandia Corporation               //
##    This Software is released under the BSD license detailed     //
##    in the file "license.txt" in the top-level Albany directory  //
##*****************************************************************//

# copy mesh files from current source dir to binary dir
set(DATA_FILES
  cube.dmg
  cube-serial0.smb
  cube0.smb
  cube1.smb
  cube2.smb
  cube3.smb
  cube-quad.dmg
  cube-quad-serial0.smb
  cube-quad0.smb
  cube-quad1.smb
  cube-quad2.smb
  cube-quad3.smb
  )

foreach(DATA_FILE IN LISTS DATA_FILES)
  ExternalData_Expand_Arguments(
      lcm_scorec_meshes_data
      OUT_DATA DATA{${DATA_FILE}}
      )
endforeach()
ExternalData_Add_Target(lcm_scorec_meshes_data)
