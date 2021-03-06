

#include "DecisionMaker.h"

UDecisionMaker::UDecisionMaker()
{
	Bonus = 0.0f;
}

UDecision* UDecisionMaker::FindBestDecision(const FDecisionContext& StartContext, FDecisionContext& OutContext, float& OutBestScore) const
{
	UDecision* best = NULL;
	for (UDecision* decision : Decisions)
	{
		if (decision != NULL)
		{
			FDecisionContext context = FDecisionContext(StartContext);
			context.Decision = decision;
			float score = decision->CalculateScore(context, OutBestScore, Bonus);
			if (score > OutBestScore)
			{
				best = decision;
				OutBestScore = score;
				OutContext = context;
			}
		}
	}
	return best;
}