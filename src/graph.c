#include <stdlib.h>

#include "raylib.h"
#include "graph.h"

LineGraph CreateLineGraph(int maxPoints, Rectangle bounds, Color lineColor)
{
	LineGraph graph;
	graph.maxPoints = maxPoints;
	graph.numPoints = 0;
	graph.xValues = (float *)malloc(maxPoints * sizeof(float));
	graph.yValues = (float *)malloc(maxPoints * sizeof(float));
	graph.bounds = bounds;
	graph.lineColor = lineColor;

	return graph;
}

void AddPoint(LineGraph *graph, float x, float y)
{
	if (graph->numPoints < graph->maxPoints)
	{
		graph->xValues[graph->numPoints] = x;
		graph->yValues[graph->numPoints] = y;
		graph->numPoints++;
	}
}

void DrawLineGraph(LineGraph *graph)
{
	DrawLineEx(
		(Vector2){graph->bounds.x, graph->bounds.y + graph->bounds.height},
		(Vector2){graph->bounds.x + graph->bounds.width, graph->bounds.y + graph->bounds.height},
		2, BLACK);

	DrawLineEx(
		(Vector2){graph->bounds.x, graph->bounds.y},
		(Vector2){graph->bounds.x, graph->bounds.y + graph->bounds.height},
		2, BLACK);

	Vector2 prevPoint = {
		graph->bounds.x + graph->xValues[0] * graph->bounds.width,
		graph->bounds.y + graph->bounds.height - graph->yValues[0] * graph->bounds.height};

	int i;
	for (i = 0; i < graph->numPoints; i++)
	{
		Vector2 currPoint = {
			graph->bounds.x + graph->xValues[i] * graph->bounds.width,
			graph->bounds.y + graph->bounds.height - graph->yValues[i] * graph->bounds.height};

		DrawLineEx(prevPoint, currPoint, 2, graph->lineColor);
		prevPoint = currPoint;
	}
}
