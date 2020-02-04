#include "EventTypes.h"
namespace Aztec {
  const int EventTypes::NONE                = 0;
  const int EventTypes::OnUpdate            = 1 << 0;
  const int EventTypes::OnClick             = 1 << 1;
  const int EventTypes::OnMouseMove         = 1 << 2;
  const int EventTypes::OnMouseDown         = 1 << 3;
  const int EventTypes::OnMouseUp           = 1 << 4;
  const int EventTypes::OnKeyDown           = 1 << 5;
  const int EventTypes::OnKeyUp             = 1 << 6;
  const int EventTypes::OnBeginContact      = 1 << 7;
  const int EventTypes::OnEndContact        = 1 << 8;
  const int EventTypes::OnMusicStarted      = 1 << 9;
  const int EventTypes::OnMusicFinished     = 1 << 10;
  const int EventTypes::OnAnimationStarted  = 1 << 11;
  const int EventTypes::OnAnimationFinished = 1 << 12;
  const int EventTypes::OnBeforeDraw        = 1 << 13;
  const int EventTypes::OnAfterDraw         = 1 << 14;


  const int EventTypes::ALL = EventTypes::OnUpdate | EventTypes::OnClick | EventTypes::OnMouseMove | EventTypes::OnMouseDown | EventTypes::OnMouseUp | EventTypes::OnKeyDown |
                              EventTypes::OnKeyUp | EventTypes::OnBeginContact | EventTypes::OnEndContact | EventTypes::OnMusicStarted | EventTypes::OnMusicFinished |
                              EventTypes::OnAnimationStarted | EventTypes::OnAnimationFinished | EventTypes::OnBeforeDraw | EventTypes::OnAfterDraw;
} // namespace Aztec