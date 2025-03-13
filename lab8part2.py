def mincost(t, denominations):
    if t < 0:
        return float('inf')
    if t == 0:
        return 0
    if t in denominations:
        return 1
    current_min = float('inf')
    for d in denominations:
        current_min = min(current_min, 1 + mincost(t-d, denominations))
    return current_min

print(mincost(8, [1, 4, 5, 10]))

def paint_house_cost_soln2(houses, col, i):
    '''Return the cost of painting houses
    0, 1, 2, ,,, i, with the i-th houses painted col
    and the total cost minimized, as well as the solution 
    that corresponds to the minimum cost'''
    if i == 0:
        return houses[col][i], [col]

    cur_min = sum(sum(costs) for costs in houses)
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue
        cost_color_i, cur_soln = paint_house_cost_soln2(houses, color, i-1)
                       # cost of painting houses 0, ...i-1
                       # with the i-1-th house painted with
                       # color color
        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
            cur_min_soln = cur_soln
        # cur_min: the smaller of the total costs
        # up to i-1, with the two colours that are allowed
        # cur_min_col: the colour that gives the smaller
        # total cost
    sol[i][col] = cur_min_col
    return houses[col][i] + cur_min, cur_min_sol + [col]  # I know that the (i-1)-st house
                                    # should be painted cur_min_col
                                    # if I paint the i-th house col