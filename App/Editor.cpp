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

std::vector<Node> nodes;
int nodeId = 1;

void RenderColorNode(Node &node)
{
    ImNodes::BeginNode(node.id);

    ImNodes::BeginNodeTitleBar();
    ImGui::TextUnformatted("Color Node");
    ImNodes::EndNodeTitleBar();

    ImNodes::BeginInputAttribute(node.input_attr);
    ImGui::Text("Input");
    ImNodes::EndInputAttribute();

    ImGui::ColorEdit4("Color", (float *)&node.color);

    ImNodes::BeginOutputAttribute(node.output_attr);
    ImGui::Text("Output");
    ImNodes::EndOutputAttribute();

    ImNodes::EndNode();
}

void RenderEditor()
{
    ImGui::Begin("Node Editor");

    ImNodes::BeginNodeEditor();

    // Renderizar todos os nós
    for (auto &node : nodes)
    {
        RenderColorNode(node);
    }

    // Criar novos nós
    if (ImGui::Button("Add Color Node"))
    {
        Node newNode;
        newNode.id = nodeId++;
        newNode.color = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
        newNode.input_attr = newNode.id << 1;
        newNode.output_attr = newNode.id << 2;
        nodes.push_back(newNode);
    }

    ImNodes::EndNodeEditor();
    ImGui::End();
}
