#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"

typedef struct LineGraph
{
	int maxPoints;
	int numPoints;
	float *xValues;
	float *yValues;
	Rectangle bounds;
	Color lineColor;
} LineGraph;

LineGraph CreateLineGraph(int maxPoints, Rectangle bounds, Color lineColor);

void AddPoint(LineGraph *graph, float x, float y);

void DrawLineGraph(LineGraph *graph);

#endif /* GRAPH_H */
