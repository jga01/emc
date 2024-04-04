#include <stdio.h>
#include <math.h>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "graph.h"

int screenWidth = 800;
int screenHeight = 600;

int main(int argc, char *argv[])
{
	InitWindow(screenWidth, screenHeight, "Graph");

	SetTargetFPS(60);

	LineGraph graph;
	graph = CreateLineGraph(100, (Rectangle){100, 100, 600, 400}, RED);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (GuiButton((Rectangle){100, 100, 600, 400}, "#05#Open Image")) { /* ACTION */ }

		// static float t = 0.0f;
		// t += 0.01f;
		// AddPoint(&graph, t, sinf(t * 5) * 0.5f + 0.5f);

		// DrawLineGraph(&graph);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
