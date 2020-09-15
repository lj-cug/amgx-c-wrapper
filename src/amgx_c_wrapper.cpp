#include <AmgXSolver.hpp>

#include "amgx_c_wrapper.h"

#include <memory>

std::unique_ptr<AmgXSolver> staticSolver = nullptr;

extern "C"
{
    void createCAmgXSolver_(CAmgXSolver* ret)
    {
        *ret = new AmgXSolver();
    }

    void destroyCAmgXSolver_(CAmgXSolver* solver)
    {
        delete *solver;
    }

    void initialize_(CAmgXSolver* solver, const MPI_Comm *comm
            , const char* modeStr, const char* cfgFile, PetscErrorCode* err)
    {
        *err = (**solver).initialize(*comm, modeStr, cfgFile);
    }

    void finalize_(CAmgXSolver* solver, PetscErrorCode* err)
    {
        *err = (**solver).finalize();
    }

    void setA_(CAmgXSolver* solver, const Mat *A, PetscErrorCode* err)
    {
        *err = (**solver).setA(*A);
    }

    void solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err)
    {
        *err = (**solver).solve(*p, *b);
    }

    void getIters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err)
    {
        *err = (**solver).getIters(*iter);
    }

    void getResidual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err)
    {
        *err = (**solver).getResidual(*iter, *res);
    }

    void createCAmgXSolverStatic_()
    {
        staticSolver.reset(new AmgXSolver());
    }

    void destroyCAmgXSolverStatic_()
    {
        staticSolver.reset(nullptr);
    }

    void initializeStatic_(const MPI_Comm *comm, PetscErrorCode* err)
    {
        initialize_(staticSolver.get(), comm, err);
    }

    void finalizeStatic_(PetscErrorCode* err)
    {
        finalizeStatic_(staticSolver.get(), err);
    }

    void setAStatic_(const Mat *A, PetscErrorCode* err)
    {
        setAStatic_(staticSolver.get(), A, err);
    }

    void solveStatic_(Vec *p, Vec *b, PetscErrorCode* err)
    {
        solveStatic_(staticSolver.get(), p, b, err);
    }

    void getItersStatic_(int *iter, PetscErrorCode* err)
    {
        getItersStatic_(staticSolver.get(), iter, err);
    }

    void getResidualStatic_(const int *iter, double *res
            , PetscErrorCode* err)
    {
        getResidualStatic_(staticSolver.get(), iter, res, err);
    }
}
