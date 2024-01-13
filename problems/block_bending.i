[GlobalParams]
    displacements = 'disp_x disp_y disp_z'
[]
[Mesh]
    [domain]
        type = GeneratedMeshGenerator
        dim = 3
        nx = 5
        ny = 5
        nz = 20
        xmax = 10
        ymax = 10
        zmax = 50
        elem_type = HEX8
    []
[]
[Modules/TensorMechanics/Master]
    [all]
        add_variables = true
        generate_output = 'vonmises_stress'
    []
[]
[BCs]
    [back_x]
        type = DirichletBC
        variable = disp_x
        boundary = back
        value = 0
    []
    [back_y]
        type = DirichletBC
        variable = disp_y
        boundary = back
        value = 0
    []
    [back_z]
        type = DirichletBC
        variable = disp_z
        boundary = back
        value = 0
    []
    [load_top]
        type = Pressure
        variable = disp_y
        boundary = top
        factor = 5   # MPa
    []
[]

[Materials]
    [elasticity]
        type = ComputeIsotropicElasticityTensor
        youngs_modulus = 210e3 # Steel
        poissons_ratio = 0.3
    []
    [stress]
        type = ComputeLinearElasticStress
    []
[]

[Executioner]
    type = Steady # Steady state problem
    solve_type = NEWTON # Perform a Newton solve
  
    # Set PETSc parameters to optimize solver efficiency
    petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
    petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
    exodus = true
[]

