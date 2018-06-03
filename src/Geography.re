[@bs.module "react-simple-maps"]
external geographyM : ReasonReact.reactClass = "Geography";

[@bs.deriving abstract]
type cssT = {
  fill: string,
  stroke: string,
  strokeWidth: float,
  outline: string,
};

[@bs.deriving abstract]
type styleT = {
  default: cssT,
  hover: cssT,
  pressed: cssT,
};

[@bs.deriving abstract]
type geographyT = {id: string};

[@bs.deriving abstract]
type jsPropsT = {
  geography: geographyT,
  projection: string,
  style: styleT,
};

let make = (~geography, ~projection, ~style, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyM,
    ~props=jsPropsT(~geography, ~projection, ~style),
    children,
  );
