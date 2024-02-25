import math

class BayesianModel:

    def __init__(self, prior_prob):
        self.prior_prob = prior_prob
        self.posterior_prob = prior_prob

    def update_probability(self, likelihood):
        # Bayesian updating formula: P(A|B) = P(B|A)*P(A) / P(B)
        # We will assume P(B), the total probability of evidence, as 1 here for simplicity.
        self.posterior_prob = likelihood * self.prior_prob
        self.prior_prob = self.posterior_prob

    def get_posterior_probability(self):
        return self.posterior_prob


class BrierScore:

    def __init__(self):
        self.forecasts = []
        self.outcomes = []

    def add_forecast(self, forecast, outcome):
        self.forecasts.append(forecast)
        self.outcomes.append(outcome)

    def calculate_brier_score(self):
        # Brier Score formula: (forecast - outcome)^2
        brier_scores = [(f - o) ** 2 for f, o in zip(self.forecasts, self.outcomes)]
        return math.sqrt(sum(brier_scores) / len(brier_scores))


if __name__ == "__main__":
    # initial prior probability
    job_model = BayesianModel(0.25)

    # update the probability
    job_model.update_probability(1)  # likelihood of getting an email
    print("Updated Probability:", job_model.get_posterior_probability())

    brier_score_calculator = BrierScore()
    brier_score_calculator.add_forecast(0.25, 1)  # initial forecast and actual outcome
    print("Brier Score:", brier_score_calculator.calculate_brier_score())
