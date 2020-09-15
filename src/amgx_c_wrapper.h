#pragma once

// AmgX
# include <amgx_c.h>

// PETSc
# include <petscmat.h>
# include <petscvec.h>

extern "C" {

    typedef struct AmgXSolver* CAmgXSolver;

    void camgx_getsolver_(CAmgXSolver* ret);

    void camgx_destroy_solver_(CAmgXSolver* solver);

    void camgx_initialize_(CAmgXSolver* solver, MPI_Fint *comm
                           , char* modeStr, char* cfgFile,  PetscErrorCode* err);

    void camgx_getinitsolver_(CAmgXSolver* ret, MPI_Fint *comm
                           , char* modeStr, char* cfgFile);

    void camgx_finalize_(CAmgXSolver* solver, PetscErrorCode* err);

    void camgx_seta_(CAmgXSolver* solver, Mat *A, PetscErrorCode* err);

    void camgx_solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err);

    void camgx_getiters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err);

    void camgx_getresidual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err);

}
