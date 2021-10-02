#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <memory>
#include <string>
#include <vector>

#include "chatbot.h"

// forward declarations
class GraphEdge;

class GraphNode {
private:
  //// STUDENT CODE
  ////

  // data handles (owned)
  /*** TASK 4- Unique pointer to manage the ownership of _childEdges ***/
  // std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
  std::vector<std::unique_ptr<GraphEdge>> _childEdges;

  // data handles (not owned)
  std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes
  /*** TASK 5 Use a local instance of ChatBot instead of a pointer ***/
  ChatBot _chatBot;

  ////
  //// EOF STUDENT CODE

  // proprietary members
  int _id;
  std::vector<std::string> _answers;

public:
  // constructor / destructor
  GraphNode(int id);
  ~GraphNode();

  // getter / setter
  int GetID() { return _id; }
  int GetNumberOfChildEdges() { return _childEdges.size(); }
  GraphEdge *GetChildEdgeAtIndex(int index);
  std::vector<std::string> GetAnswers() { return _answers; }
  int GetNumberOfParents() { return _parentEdges.size(); }

  // proprietary functions
  void AddToken(std::string token); // add answers to list
  void AddEdgeToParentNode(GraphEdge *edge);
  /*** TASK 4 ***/
  void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

  //// STUDENT CODE
  ////

  /*** TASK 5 With instance of ChatBot pass by argument we can invoke Copy
   * Constructor (with Lvalue) or Move Constructor (with Rvalue) ***/
  void MoveChatbotHere(ChatBot chatbot);

  ////
  //// EOF STUDENT CODE

  void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */