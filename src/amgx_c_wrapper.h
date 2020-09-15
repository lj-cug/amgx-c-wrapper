#ifndef __AMGX_C_WRAPPER_H
#define __AMGX_C_WRAPPER_H

#pragma once

// AmgX
# include <amgx_c.h>

// PETSc
# include <petscmat.h>
# include <petscvec.h>

extern "C" {

    struct CAmgXSolver;
    typedef struct CAmgXSolver CAmgXSolver;

    CAmgXSolver* createCAmgXSolver();

    void destroyCAmgXSolver(CAmgXSolver* solver);

    PetscErrorCode initialize(CAmgXSolver* solver, const MPI_Comm &comm,
                            const char* modeStr, const char* cfgFile);

    PetscErrorCode finalize(CAmgXSolver* solver);

    PetscErrorCode setA(CAmgXSolver* solver, const Mat &A);

    PetscErrorCode solve(CAmgXSolver* solver, Vec &p, Vec &b);

    PetscErrorCode getIters(CAmgXSolver* solver, int &iter);

    PetscErrorCode getResidual(CAmgXSolver* solver, const int &iter, double &res);

}

#endif
