#include <AmgXSolver.hpp>

#include "amgx_c_wrapper.h"

extern "C"
{
    void create_camgx_solver_(CAmgXSolver* ret)
    {
        *ret = new AmgXSolver();
    }

    void destroy_camgx_solver_(CAmgXSolver* solver)
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

    void set_a_(CAmgXSolver* solver, const Mat *A, PetscErrorCode* err)
    {
        *err = (**solver).setA(*A);
    }

    void solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err)
    {
        *err = (**solver).solve(*p, *b);
    }

    void get_iters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err)
    {
        *err = (**solver).getIters(*iter);
    }

    void get_residual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err)
    {
        *err = (**solver).getResidual(*iter, *res);
    }
}
