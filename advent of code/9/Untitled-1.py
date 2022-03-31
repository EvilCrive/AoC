def read(filename):
    lines = open(filename).readlines()
    width = len(lines[0])
    zline = [10 for i in range(width + 1)]
    result = [zline]
    for l in lines:
        n = list(l)
        if n[len(n) - 1] == "\n":
            n = n[:-1]
        n = [10] + n + [10]
        result.append(list(map(int, n)))
    result.append(zline)
    return result


def calc_low_points(map):
    result = []
    for x in range(1, len(map) - 1):
        for y in range(1, len(map[0]) - 1):
            others = [map[x][y-1], map[x][y+1], map[x+1][y], map[x-1][y]]
            if not [v for v in others if map[x][y] >= v]:
                result.append((x, y))
    return result


def walk(map, startx, starty):
    todo = [(startx, starty)]
    done = []
    size = 0
    while len(todo) > 0:
        size = size + 1
        (x, y) = todo.pop(0)
        done.append((x, y))
        others = [(x, y-1), (x, y+1), (x+1, y), (x-1, y)]
        for other in others:
            otherv = map[other[0]][other[1]]
            if otherv < 9 and otherv > map[x][y]:
                if not other in done and not other in todo:
                    todo.append(other)
    return size

if __name__ == "__main__":
    lines = read("input")
    sizes = []
    for i in calc_low_points(lines):
        sizes.append(walk(lines, i[0], i[1]))
    sizes.sort()
    sizes.reverse()
    result=calc_low_points(lines)
    print(calc_low_points(lines))
