import { StateCreator } from "zustand";

export interface SettingsSlice {
  darkMode: boolean;
  setDarkMode: (enabled: boolean) => void;
}

export const createSettingsSlice: StateCreator<
  SettingsSlice,
  [],
  [],
  SettingsSlice
> = (set) => ({
  darkMode: false,

  setDarkMode: (enabled) =>
    set({
      darkMode: enabled,
    }),
});
