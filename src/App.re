[@bs.module "electron"] [@bs.scope "app"]
external on:
  (
    [@bs.string] [
      | [@bs.as "ready"] `Ready
      | [@bs.as "before-quit"] `BeforeQuit
      | [@bs.as "will-quit"] `WillQuit
      | [@bs.as "quit"] `Quit
      | [@bs.as "closed"] `Closed
      | [@bs.as "window-all-closed"] `WindowAllClosed
      | [@bs.as "activate"] `Activate
    ],
    unit => unit
  ) =>
  unit =
  "";

/* Couldn't figure out how to deprecate a single argument to `on`.
 * Remove when `Closed is removed
 */
let on = (event, cb) => {
  if (event == `Closed) {
    prerr_endline(
      "Warning: The `Closed event doesn't do anything and is deprecated. Use `Quit instead.",
    );
  };
  on(event, cb);
};

[@bs.module "electron"] [@bs.scope "app"] external quit: unit => unit = "";

module Dock = {
  [@bs.module "electron"] [@bs.scope ("app", "dock")]
  external hide: unit => unit = "";
};
