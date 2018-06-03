[@bs.module "react-simple-maps"]
external composableMap : ReasonReact.reactClass = "ComposableMap";

[@bs.deriving abstract]
type projectionConfigT = {
  scale: int,
  rotation: list(int),
};

[@bs.deriving abstract]
type jsProps = {
  width: int,
  height: int,
  projectionConfig: projectionConfigT,
};

let make = (~width, ~height, ~projectionConfig, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMap,
    ~props=jsProps(~width, ~height, ~projectionConfig),
    children,
  );
