#pragma once
#include "imgui.h"
#include "imnodes.h"
#include <vector>
#include <string>
// Estrutura básica do nó
struct Node
{
    int id;
    ImVec4 color;
    int input_attr, output_attr;
};
struct Link
{
    int id;
    int start_attr; // Output attribute ID
    int end_attr;   // Input attribute ID
};
void RenderColorNodeMain(Node &node);

void RenderEditorMain();
