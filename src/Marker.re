[@bs.module "react-simple-maps"]
external markerM : ReasonReact.reactClass = "Marker";

[@bs.deriving abstract]
type markerT = {
  markerOffset: int,
  name: string,
  coordinates: (float, float),
};

[@bs.deriving abstract]
type cssT = {
  fill: string,
};

[@bs.deriving abstract]
type styleT = {
  default: cssT,
  hover: cssT,
  pressed: cssT,
};

[@bs.deriving abstract]
type jsPropsT = {
  marker: markerT,
  style: styleT,
};

let make = (~marker, ~style, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerM,
    ~props=jsPropsT(~marker, ~style,),
    children
  );
