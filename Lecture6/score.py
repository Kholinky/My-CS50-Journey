from cs50 import get_int

scores = []

for i in range(3):
    score = get_int("Scores: ")
    scores.append(score)

average = sum(scores) / len(scores)

print(f"average: {average}")
