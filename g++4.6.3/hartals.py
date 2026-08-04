import sys


def main():
    data = list(map(int, sys.stdin.read().split()))
    if not data:
        return

    index = 0
    test_cases = data[index]
    index += 1
    answers = []

    for _ in range(test_cases):
        days = data[index]
        parties = data[index + 1]
        index += 2

        hartal_parameters = data[index:index + parties]
        index += parties

        lost_days = [False] * (days + 1)

        for h in hartal_parameters:
            for day in range(h, days + 1, h):
                lost_days[day] = True

        for day in range(6, days + 1, 7):
            lost_days[day] = False
        for day in range(7, days + 1, 7):
            lost_days[day] = False

        answers.append(str(sum(lost_days[1:])))

    sys.stdout.write("\n".join(answers))


if __name__ == "__main__":
    main()
