#ifndef OMPL_NEAR_PROJECTION_PNEARKPIECE1_H
#define OMPL_NEAR_PROJECTION_PNEARKPIECE1_H

#include <ompl/geometric/planners/kpiece/KPIECE1.h>
#include <thread>
#include <mutex>

namespace ompl_near_projection {
  namespace geometric {
    class pNearKPIECE1 : public ompl::geometric::KPIECE1 {
    public:
      pNearKPIECE1(const ompl::base::SpaceInformationPtr &si) : KPIECE1(si) {}

      ompl::base::PlannerStatus solve(const ompl::base::PlannerTerminationCondition &ptc) override;

      void setThreadCount(unsigned int nthreads) {
        assert(nthreads > 0);
        threadCount_ = nthreads;
      }

      unsigned int getThreadCount() const {
        return threadCount_;
      }
    protected:
      struct SolutionInfo
      {
        Motion *solution;
        Motion *approxsol;
        double approxdif;
        std::mutex lock;
      };

      void threadSolve(unsigned int tid, const ompl::base::PlannerTerminationCondition &ptc, SolutionInfo *sol);

      std::mutex discLock_;
      unsigned int threadCount_ = 2;
    };
  }
};

#endif
