#include <AmgXSolver.hpp>

#include "amgx_c_wrapper.h"
#include <stdio.h>
#include <string.h>
#include <mpi.h>
extern "C"
{

typedef int fint;		/* this must correspond to above */

/*****************************************************************/

    void camgx_getsolver_(CAmgXSolver* ret)
    {
        *ret = new AmgXSolver();
    }

    void camgx_destroy_solver_(CAmgXSolver* solver)
    {
        delete *solver;
    }

    void camgx_initialize_(CAmgXSolver* solver, MPI_Fint *comm
                           , char* modeStr, char* cfgFile,  PetscErrorCode* err)
    {
        MPI_Comm Ccomm;
        Ccomm=MPI_Comm_f2c(*comm);
        *err = (**solver).initialize(Ccomm, modeStr, cfgFile);
    }

    void camgx_getinitsolver_(CAmgXSolver* ret, MPI_Fint *comm, char* modeStr, char* cfgFile)
    {
        MPI_Comm Ccomm;
        Ccomm=MPI_Comm_f2c(*comm);
        *ret = new AmgXSolver(Ccomm, modeStr, cfgFile);
    }

    void camgx_finalize_(CAmgXSolver* solver, PetscErrorCode* err)
    {
        *err = (**solver).finalize();
    }

    void camgx_seta_(CAmgXSolver* solver, Mat *A, PetscErrorCode* err)
    {
        *err = (**solver).setA(*A);
    }

    void camgx_solve_(CAmgXSolver* solver, Vec *p, Vec *b, PetscErrorCode* err)
    {
        *err = (**solver).solve(*p, *b);
    }

    void camgx_getiters_(CAmgXSolver* solver, int *iter, PetscErrorCode* err)
    {
        *err = (**solver).getIters(*iter);
    }

    void camgx_getresidual_(CAmgXSolver* solver, const int *iter, double *res
            , PetscErrorCode* err)
    {
        *err = (**solver).getResidual(*iter, *res);
    }
}
