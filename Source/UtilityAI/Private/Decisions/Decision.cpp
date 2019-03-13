


#include "Decision.h"

float UDecision::CalculateScore(FDecisionContext Context, float MinToBeat)
{
	if (DecisionScoreEvaluator == NULL)
	{
		return 0.0f;
	}
	else
	{
		return DecisionScoreEvaluator->CalculateScore(Context, MinToBeat);
	}
}
