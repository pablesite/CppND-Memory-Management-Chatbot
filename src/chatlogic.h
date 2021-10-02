#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <string>
#include <vector>

#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic {
private:
  //// STUDENT CODE
  ////

  // data handles (owned)
  /*** TASK 3 Declare unique ptr in order to the instances of GraphNodes to
   * which the vector elements refer are exclusively owned by the class
   * ChatLogic***/
  std::vector<std::unique_ptr<GraphNode>> _nodes;

  /*** TASK 4 _edges vector is not necessary in ChatLogic. Ownership of edges is
   * located in GraphNode through _childEdges vector. In ChatLogic also exist
   * _parentEdges vector which contains references to edges handles in
   * _childEdges vector ***/
  // std::vector<GraphEdge *> _edges;

  ////
  //// EOF STUDENT CODE

  // data handles (not owned)
  GraphNode *_currentNode;
  ChatBot *_chatBot;
  ChatBotPanelDialog *_panelDialog;

  // proprietary type definitions
  typedef std::vector<std::pair<std::string, std::string>> tokenlist;

  // proprietary functions
  template <typename T>
  void AddAllTokensToElement(std::string tokenID, tokenlist &tokens,
                             T &element);

public:
  // constructor / destructor
  ChatLogic();
  ~ChatLogic();

  // getter / setter
  void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
  void SetChatbotHandle(ChatBot *chatbot);

  // proprietary functions
  void LoadAnswerGraphFromFile(std::string filename);
  void SendMessageToChatbot(std::string message);
  void SendMessageToUser(std::string message);
  wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */