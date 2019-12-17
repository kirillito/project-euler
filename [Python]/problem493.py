# Under The Rainbow
# 70 coloured balls are placed in an urn, 10 for each of the seven rainbow colours.
# What is the expected number of distinct colours in 20 randomly picked balls?
# Give your answer with nine digits after the decimal point (a.bcdefghij).
from euler import choose

colors = 7
ballsPerColor = 10
ballsPicked = 20
totalBalls = ballsPerColor * colors
minNumberOfColors = ballsPicked / ballsPerColor

def singleColorProbability():
    return  1 - choose(totalBalls - ballsPerColor, ballsPicked)/choose(totalBalls, ballsPicked)

print(colors * singleColorProbability())