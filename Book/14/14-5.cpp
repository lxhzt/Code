// 利用有向面积计算多边形的面积，注意最后结果取绝对值，因为顶点顺序可能并不是按逆时针方向给出。
double area(point vertex[], int n)
{
	double apg = 0.0;
	if (n < 3) return apg;
	for (int i = 0, j = 1; i < n; i++, j = (i + 1) % n)
		apg += (vertex[i].x * vertex[j].y - vertex[j].x * vertex[i].y);
	return fabs(apg / 2.0);
}

double area(polygon &pg)
{
    double apg = 0.0;
    int n = pg.size();
    if (n < 3) return apg;
    for (int i = 0, j = 1; i < n; i++, j = (i + 1) % n)
        apg += (pg[i].x * pg[j].y - pg[j].x * pg[i].y);
    return fabs(apg / 2.0);
}
