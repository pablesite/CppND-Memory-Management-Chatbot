#include "graphnode.h"
#include "graphedge.h"

#include <iostream>

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  /*** TASK 0. At first, _chatBot is deallocated in chatlogic ***/
  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

/*** TASK 4 Use of move semantics to transfer ownership of edge***/
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
/*** TASK 5 With Chatbot argument and rValue passed to this function, move
 * constructor is invoked.
 * To assign chatbot to _chatbot, it is used again move semantics to "make a
 * transfer" of the instance  ***/
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

/*** TASK 5 _chatBot isn't a pointer anymore so it is not necessary invalidate
 * the pointer. Also memory allocated in chatBot is managed with rule of Five in
 * ChatBot class ***/
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(_chatBot);
  //_chatBot = nullptr; // invalidate pointer at source
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  /*** TASK 4 Use of get() property from unique_ptr to get the adress***/
  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}