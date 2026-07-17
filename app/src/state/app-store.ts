import { create } from "zustand";
import { persist, createJSONStorage } from "zustand/middleware";
import AsyncStorage from "@react-native-async-storage/async-storage";

import { createSettingsSlice, SettingsSlice } from "./slices/settings-slice";

type AppStore = SettingsSlice;

export const useAppStore = create<AppStore>()(
  persist(
    (...args) => ({
      ...createSettingsSlice(...args),
    }),
    {
      name: "vexel-storage",
      storage: createJSONStorage(() => AsyncStorage),
    },
  ),
);
