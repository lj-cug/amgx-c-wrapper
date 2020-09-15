#pragma once

// AmgX
# include <amgx_c.h>

// PETSc
# include <petscmat.h>
# include <petscvec.h>

extern "C" {

    typedef struct AmgXSolver* CAmgXSolver;

    void createCAmgXSolver_(CAmgXSolver* ret);

    void destroyCAmgXSolver_(CAmgXSolver* solver);

    void initialize_(CAmgXSolver* solver, const MPI_Comm *comm
            , const char* modeStr, const char* cfgFile, PetscErrorCode* err);

    void finalize_(CAmgXSolver* solver, PetscErrorCode* err);

    void setA_(CAmgXSolver* solver, const Mat *A, PetscErrorCode* err);

    void solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err);

    void getIters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err);

    void getResidual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err);

}
