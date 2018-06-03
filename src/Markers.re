[@bs.module "react-simple-maps"]
external markers : ReasonReact.reactClass = "Markers";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass=markers, ~props={}, children);
