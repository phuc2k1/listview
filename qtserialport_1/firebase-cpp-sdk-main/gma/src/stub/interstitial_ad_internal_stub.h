/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIREBASE_GMA_SRC_STUB_INTERSTITIAL_AD_INTERNAL_STUB_H_
#define FIREBASE_GMA_SRC_STUB_INTERSTITIAL_AD_INTERNAL_STUB_H_

#include "gma/src/common/interstitial_ad_internal.h"

namespace firebase {
namespace gma {
namespace internal {

/// Stub version of InterstitialAdInternal, for use on desktop platforms. GMA
/// is forbidden on desktop, so this version creates and immediately completes
/// the Future for each method.
class InterstitialAdInternalStub : public InterstitialAdInternal {
 public:
  explicit InterstitialAdInternalStub(InterstitialAd* base)
      : InterstitialAdInternal(base) {}

  ~InterstitialAdInternalStub() override {}

  Future<void> Initialize(AdParent parent) override {
    return CreateAndCompleteFutureStub(kInterstitialAdFnInitialize);
  }

  Future<AdResult> LoadAd(const char* ad_unit_id,
                          const AdRequest& request) override {
    return CreateAndCompleteAdResultFutureStub(kInterstitialAdFnLoadAd);
  }

  Future<void> Show() override {
    return CreateAndCompleteFutureStub(kInterstitialAdFnShow);
  }

  bool is_initialized() const override { return true; }

 private:
  Future<void> CreateAndCompleteFutureStub(InterstitialAdFn fn) {
    CreateAndCompleteFuture(fn, kAdErrorCodeNone, nullptr, &future_data_);
    return GetLastResult(fn);
  }

  Future<AdResult> CreateAndCompleteAdResultFutureStub(InterstitialAdFn fn) {
    return CreateAndCompleteFutureWithResult(fn, kAdErrorCodeNone, nullptr,
                                             &future_data_, AdResult());
  }
};

}  // namespace internal
}  // namespace gma
}  // namespace firebase

#endif  // FIREBASE_GMA_SRC_STUB_INTERSTITIAL_AD_INTERNAL_STUB_H_
