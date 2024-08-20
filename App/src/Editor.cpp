#include "Editor.h"

// Global containers for nodes and links
std::vector<Node> nodes;
std::vector<Link> links;

int _nodeId = 1;
int _linkId = 1;

void RenderColorNodeMain(Node &node)
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

void RenderEditorMain()
{
    ImGui::Begin("Node Editor");

    ImNodes::BeginNodeEditor();

    // Render all nodes
    for (auto &node : nodes)
    {
        RenderColorNodeMain(node);
    }

    // Render all links
    for (auto &link : links)
    {
        ImNodes::Link(link.id, link.start_attr, link.end_attr);
    }

    // Handle new link creation
    int start_attr, end_attr;
    if (ImNodes::IsLinkCreated(&start_attr, &end_attr))
    {
        links.push_back({_linkId++, start_attr, end_attr});
    }

    // Handle new node creation
    if (ImGui::Button("Add Color Node"))
    {
        Node newNode;
        newNode.id = _nodeId++;
        newNode.color = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
        newNode.input_attr = newNode.id << 1;
        newNode.output_attr = newNode.id << 2;
        nodes.push_back(newNode);
    }

    ImNodes::EndNodeEditor();
    ImGui::End();
}
