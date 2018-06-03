[@bs.module "react-simple-maps"]
external geographies : ReasonReact.reactClass = "Geographies";

[@bs.deriving abstract]
type jsPropsT = {geography: string};

let make = (~geography, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographies,
    ~props=jsPropsT(~geography),
    children
  )
