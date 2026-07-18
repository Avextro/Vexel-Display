import AsyncStorage from "@react-native-async-storage/async-storage";

import { useAppStore } from "./app-store";

jest.mock("@react-native-async-storage/async-storage");

const storeResetFns = new Set<() => void>();

const initialState = useAppStore.getState();

storeResetFns.add(() => {
  useAppStore.setState(initialState, true);
});

export function resetStores() {
  storeResetFns.forEach((reset) => reset());
}

describe("App Store", () => {
  beforeEach(() => {
    resetStores();
    jest.clearAllMocks();
  });

  describe("Settings Slice", () => {
    test("should initialise with dark mode disabled", () => {
      expect(useAppStore.getState().darkMode).toBe(false);
    });

    test("should enable dark mode", () => {
      useAppStore.getState().setDarkMode(true);

      expect(useAppStore.getState().darkMode).toBe(true);
    });

    test("should disable dark mode", () => {
      useAppStore.getState().setDarkMode(false);

      expect(useAppStore.getState().darkMode).toBe(false);
    });

    test("should persist settings changes", () => {
      useAppStore.getState().setDarkMode(true);

      expect(AsyncStorage.setItem).toHaveBeenCalled();
    });
  });
});
