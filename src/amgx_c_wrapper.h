#pragma once

// AmgX
# include <amgx_c.h>

// PETSc
# include <petscmat.h>
# include <petscvec.h>

extern "C" {

    typedef struct AmgXSolver* CAmgXSolver;

    void create_camgx_solver_(CAmgXSolver* ret);

    void destroy_camgx_solver_(CAmgXSolver* solver);

    void initialize_(CAmgXSolver* solver, const MPI_Comm *comm
            , const char* modeStr, const char* cfgFile, PetscErrorCode* err);

    void finalize_(CAmgXSolver* solver, PetscErrorCode* err);

    void set_a_(CAmgXSolver* solver, const Mat *A, PetscErrorCode* err);

    void solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err);

    void get_iters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err);

    void get_residual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err);

}
