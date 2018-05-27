type state = {markers: array(Fetcher.data)};

type action =
  | Loaded(array(Fetcher.data));

let component = ReasonReact.reducerComponent("Wrapper");

let make = children => {
  ...component,
  initialState: () => {markers: [||]},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(markers) => ReasonReact.Update({markers: markers})
    },
  didMount: self => {
    Fetcher.fetchPost(
      ~url="https://immense-river-25513.herokuapp.com/add-location",
      ~body="janmarsicek",
    );
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=data =>
      self.send(Loaded(data))
    );
  },
  render: _self => <div> (ReasonReact.array(children)) </div>,
};