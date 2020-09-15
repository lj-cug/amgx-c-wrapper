#include <AmgXSolver.hpp>

#include "amgx_c_wrapper.h"

extern "C"
{
    CAmgXSolver* createCAmgXSolver() {
        return reinterpret_cast<CAmgXSolver*>(new AmgXSolver());
    }

    void destroyCAmgXSolver(CAmgXSolver* solver) {
        delete reinterpret_cast<AmgXSolver*>(solver);
    }

    PetscErrorCode initialize(CAmgXSolver* solver, const MPI_Comm &comm, const char* modeStr, const char* cfgFile) {
        return reinterpret_cast<AmgXSolver*>(solver)->initialize(comm, modeStr, cfgFile);
    }

    PetscErrorCode finalize(CAmgXSolver* solver) {
        return reinterpret_cast<AmgXSolver*>(solver)->finalize();
    }

    PetscErrorCode setA(CAmgXSolver* solver, const Mat &A) {
        return reinterpret_cast<AmgXSolver*>(solver)->setA(A);
    }

    PetscErrorCode solve(CAmgXSolver* solver, Vec &p, Vec &b) {
        return reinterpret_cast<AmgXSolver*>(solver)->solve(p, b);
    }

    PetscErrorCode getIters(CAmgXSolver* solver, int &iter) {
        return reinterpret_cast<AmgXSolver*>(solver)->getIters(iter);
    }

    PetscErrorCode getResidual(CAmgXSolver* solver, const int &iter, double &res) {
        return reinterpret_cast<AmgXSolver*>(solver)->getResidual(iter, res);
    }
}
