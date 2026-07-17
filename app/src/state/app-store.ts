import {create} from "zustand";
import { createSettingsSlice, SettingsSlice } from "./slices/settings-slice";

type AppStore = SettingsSlice;

export const useAppStore = create<AppStore>()((...args) => ({
    ...createSettingsSlice(...args),
}));