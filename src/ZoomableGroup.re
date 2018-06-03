[@bs.module "react-simple-maps"]
external zoomableGroup : ReasonReact.reactClass = "ZoomableGroup";

[@bs.deriving abstract]
type jsPropsT = {
  center: list(int),
  disablePanning: bool,
};

let make = (~center, ~disablePanning, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroup,
    ~props=jsPropsT(~center, ~disablePanning),
    children,
  );
